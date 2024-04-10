#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


#include <tuple>


void re(int& x);
void re(long long& x);


void re(char* c);
template<class T, class... Ts> void re(T& t, Ts&... ts);


struct SuffixArray {
    int *rank, *lcpi, *SA;
    int log;

    SuffixArray(int* s, int n, int K);
    ~SuffixArray();
    int lcp(int a, int b) const;
    int cmp(int a, int len_a, int b, int len_b) const;
private:
    static void radixPass(int* a, int* b, int* r, int n, int K);
    inline bool leq(int a1, int a2, int b1, int b2);
    inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3);
    void suffixArray(int *s, int *SA, int n, int K);
    void kasai(int *s, int n);
};


typedef pair<int, int> pii;


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n,m;
long long k;
char s[1100];
int si[1100];
int min_take[1100];
long long dp[1100][1100];
long long sumdp[1100][1100];

long long check(const SuffixArray& sa, pii cand) {
    for (int i = 0; i < n; i++) {
        int st = 1, ed = n - i;
        while (st < ed) {
            int md = (st+ed)/2;
            if (sa.cmp(cand.first, cand.second, i, md) == 1) st=md+1;
            else ed=md;
        }
        if (sa.cmp(cand.first, cand.second, i, st) == 1) min_take[i] = -1;
        else min_take[i] = st;
    }

    memset(dp,0,sizeof(dp));
    memset(sumdp,0,sizeof(sumdp));
    dp[n][0] = sumdp[n][0] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int needs = 0; needs <= m; needs++) {
            if (min_take[i] != -1 && needs) dp[i][needs] = sumdp[i + min_take[i]][needs-1];

            sumdp[i][needs] = min(k+1, dp[i][needs] + sumdp[i+1][needs]);
        }
    }

    //printf("cand: %d %d --> %lld\n", cand.first,cand.second,k);
    return dp[0][m];
}

void solve()
{
    re(n,m,k);
    re(s);

    rep(i,0,n) si[i] = s[i]-'a'+1;
    SuffixArray sa(si, n, 26);

    vector<pii> all_strings;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            all_strings.emplace_back(i, j-i);
        }
    }
    sort(all_strings.begin(), all_strings.end(), [&](pii &a, pii &b) {
        return sa.cmp(a.first, a.second, b.first, b.second) == -1;
    });

    all_strings.erase(unique(all_strings.begin(), all_strings.end(), [&](pii &a, pii &b) {
        return sa.cmp(a.first, a.second, b.first, b.second) == 0;
    }), all_strings.end());

    int st = 0, ed = all_strings.size()-1;
    while (st < ed) {
        int md = (st+ed+1)/2;
        long long hm = check(sa, all_strings[md]);
        if (hm >= k) st = md;
        else ed = md-1;
    }

    rep(i,0,all_strings[st].second) printf("%c", s[all_strings[st].first + i]);
}


int main() {


    solve();
}


// lexicographic order for pairs
inline bool SuffixArray::leq(int a1, int a2, int b1, int b2) {
    return(a1 < b1 || (a1 == b1 && a2 <= b2));
}

// and triples
inline bool SuffixArray::leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));
} // and triples

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
void SuffixArray::radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
    int* c = new int[K + 1]; // counter array
    for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
    for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0;  i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
    delete [] c;
}

SuffixArray::~SuffixArray() {
    delete [] SA; delete [] rank; delete [] lcpi;
}

// find the suffix array SA of s[0..n-1] in {1..K}n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
SuffixArray::SuffixArray(int* s, int n, int K) {
    SA = new int[n];
    if (n == 1) SA[0] = 0;
    else suffixArray(s,SA,n,K);
    kasai(s,n);
}

void SuffixArray::suffixArray(int *s, int *SA, int n, int K) {
    
    int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
    int* s12 = new int[n02+3]; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
    int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
    int* s0 = new int[n0];
    int* SA0 = new int[n0];
    // generate positions of mod 1 and mod 2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i=0, j=0; i < n + (n0-n1); i++)
        if (i%3 != 0) s12[j++] = i;
    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s  , n02, K);
    // find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
            name++;
            c0 = s[SA12[i]];
            c1 = s[SA12[i]+1];
            c2 = s[SA12[i]+2];
        }
        if (SA12[i]%3 == 1) s12[SA12[i]/3] = name; // left half
        else s12[SA12[i]/3 + n0] = name; // right half
    }
    // recurse if names are not yet unique
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else // generate the suffix array of s12 directly
        for (int i = 0;  i < n02; i++) SA12[s12[i] - 1] = i;
    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++)
        if (SA12[i] < n0) s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);
    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0-n1, k = 0; k < n; k++) {
        #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GetI(); // pos of current offset 12 suffix
        int j = SA0[p]; // pos of current offset 0 suffix
        if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
            leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
        {// suffix from SA12 is smaller
            SA[k] = i; t++;
            if (t == n02) // done --- only SA0 suffixes left
            for (k++; p < n0; p++, k++) SA[k] = SA0[p];
        } else {// suffix from SA0 is smaller
            SA[k] = j; p++;
            if (p == n0) // done --- only SA12 suffixes left
            for (k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

void SuffixArray::kasai(int *s, int n)
{
    log = log2(n); log++;

    int k=0;
    lcpi = new int[n*log];

    rank = new int[n];

    for(int i=0; i<n; i++) rank[SA[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=SA[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcpi[rank[i]*log]=k;
    }

    for (int j = 1; j < log; j++) {
        for (int i = 0; i < n; i++) {
            lcpi[i*log + j] = lcpi[i*log + (j-1)];
            if (i+(1<<(j-1)) < n) lcpi[i*log+j] = std::min(lcpi[i*log+j], lcpi[ (i + (1<<(j-1)))*log + (j-1)]); 
        }
    }
} 

int SuffixArray::lcp(int a, int b) const {
    if (a == b) return n - SA[a];
    if (a > b) std::swap(a,b);
    int l = log2(b-a);
    return std::min(lcpi[a*log + l], lcpi[(b - (1<<l))*log + l]);
}

int SuffixArray::cmp(int a, int len_a, int b, int len_b) const {
    int ra = rank[a];
    int rb = rank[b];
    int common = lcp(ra, rb);

    if (std::min(len_a, len_b) <= common) {
        if (len_a == len_b) return 0;
        return len_a < len_b ? -1 : 1;
    }
    return ra < rb ? -1 : 1;
}


void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }


void re(char* c) { scanf("%s", c); }
template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


#include <array>