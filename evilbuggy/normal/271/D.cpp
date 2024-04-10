#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

struct SPair{
    int posl, posr, ind;
};

bool cmp(SPair &a, SPair &b){
    return (a.posl == b.posl)?(a.posr < b.posr):(a.posl < b.posl);
}

struct SuffixArray{

    int n, lg;
    string s;
    vector<int> sa, log2, pos;
    vector<vector<int> > p, lcp;

    SuffixArray(string is){
        s = is;
        n = s.size();
        sa = vector<int> (n);
        pos = vector<int> (n);
        log2 = vector<int> (n + 1);
        lg = 1;
        while(n >= (1<<lg))lg++;
        p = vector<vector<int> > (n, vector<int> (lg + 1));
        lcp = vector<vector<int> > (n, vector<int> (lg + 1));

        log2[1] = 0;
        for(int i = 2; i <= n; i++){
            log2[i] = log2[i/2] + 1;
        }
    }

    void buildSA(){
        SPair arr[n];
        int lg = 1;
        while(n >= (1<<lg))lg++;
        for(int i = 0; i < n; i++){
            p[i][0] = s[i] - 'a';
        }
        for(int k = 1, len = 1; k <= lg; k++, len <<= 1){
            for(int i = 0; i < n; i++){
                arr[i].posl = p[i][k-1];
                arr[i].posr = (i + len < n)?p[i + len][k-1]:-1;
                arr[i].ind = i;
            }
            sort(arr, arr + n, cmp);
            for(int i = 0; i < n; i++){
                if(i == 0 || (arr[i].posl != arr[i-1].posl || arr[i].posr != arr[i-1].posr)){
                    p[arr[i].ind][k] = i;
                }else{
                    p[arr[i].ind][k] = p[arr[i-1].ind][k];
                }
            }
        }
        for(int i = 0; i < n; i++){
            sa[p[i][lg]] = i;
            pos[i] = p[i][lg];
        }
    }

    int findLCP(int x, int y){
        int ans = 0;
        for(int i = lg; i >= 0 && x < n && y < n; i--){
            if(p[x][i] == p[y][i]){
                ans += (1<<i);
                x  += (1<<i);
                y += (1<<i);
            }
        }
        return ans;
    }

    void buildLCP(){
        for(int i = 1; i < n; i++){
            lcp[i][0] = findLCP(sa[i-1], sa[i]);
        }
        for(int k = 1; k <= lg; k++){
            for(int i = 1; i < n; i++){
                if(i + (1<<k) < n){
                    lcp[i][k] = min(lcp[i][k-1], lcp[i + (1<<k)][k-1]);
                }else{
                    lcp[i][k] = lcp[i][k-1];
                }
            }
        }
    }

    int queryLCP(int x, int y){
        x = pos[x];
        y = pos[y];
        if(x == y)return n-x;
        if(x < y)swap(x, y);
        int k = log2[(x-y+1)];
        return min(lcp[x][k], lcp[y - (1<<k) + 1][k]);
    }
};

bool bad[26];
int mlen[1555], sum[1555];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    SuffixArray sufArr(s);
    sufArr.buildSA();
    // cout<<"Built SA"<<endl;
    sufArr.buildLCP();
    // cout<<"Built LCP"<<endl;
    
    char ch;
    for(int i = 0; i < 26; i++){
        cin>>ch;
        bad[i] = (ch == '0');
    }

    for(int i = 0; i < n; i++){
        sum[i] = bad[s[i] - 'a'];
        if(i != 0)sum[i] += sum[i-1];
    }

    int k;
    cin>>k;

    memset(mlen, 0, sizeof(mlen));
    int l = 0, r = 0;
    while(l < n){
        while(r < n && sum[r] - (l != 0?sum[l-1]:0) < k+1){
            r++;
        }
        mlen[l] = (r-l);
        l++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += mlen[i];
        // cout<<mlen[i]<<endl;
    }
    for(int i = 1; i < n; i++){
        int l1 = mlen[sufArr.sa[i-1]];
        int l2 = mlen[sufArr.sa[i]];
        int l3 = sufArr.lcp[i][0];
        ans -= min(min(l1, l2), l3);
        // ans -= l3;
        // cout<<sufArr.sa[i]<<" "<<mlen[sufArr.sa[i]]<<endl;
    }
    cout<<ans<<endl;
}