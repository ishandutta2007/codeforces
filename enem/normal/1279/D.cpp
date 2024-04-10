#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef double DB;
typedef float FL;
typedef vector<LL> VL;
typedef tuple<LL, LL, LL> TTL;
typedef tuple<LL, LL, LL, LL> TFL;
const LL N=pow(10, 9)+7;
const LL NN=998244353;

#define FAST(a, b, c, d) ios::sync_with_stdio(a); cin.tie(b); cout.tie(c);cout<<fixed<<setprecision(d);
#define RW(a, b) freopen(a, "r", stdin); freopen(b, "w", stdout);
#define IN(a, n) for(LL i=0; i<n; i++) cin>>a[i];
#define PN(a) for(auto i:a) cout<<i<<" "; cout<<endl;
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << t<<" "; return os << endl; }
#define V(a) vector<a>
#define P(a) pair<a, a>
#define endl "\n"
#define REP(i, a, b, k) for(LL i=a; i<b; i+=k)
#define RREP(i, a, b, k) for(LL i=a; i>b; i-=k)
#define PB push_back
#define PF pop_front
#define MP make_pair
#define MT make_tuple
#define G(i, a) get<i>(a)
#define F first
#define S second

LL MIN(LL a, LL b) // returns the minimum of two numbers a and b
{
    if(a<b) return a;
    else return b;
}

LL MAX(LL a, LL b) // returns the maximum of two numbers a and b
{ 
    if(a>b) return a;
    else return b;
}

void swap(LL *a, LL *b) // swaps the two numbers
{ 
    LL *x=a;
    a=b;
    b=x;
}

LL SOD(LL a) // returns sum of digits of a decimal number
{ 
    VL v;
    LL sum=0;
    while(a!=0)
    {
        v.PB(a%10);
        if(a%10==4||a%10==7) sum++;
        a=a/10;
    }
    return sum;
}

LL NUM1(LL a) // returns the count of number of 1's in binary representation of a decimal number
{ 
    LL s=0;
    while(a!=0)
    {
        if(a%2==1)
        {
            s++;
        }
        a=a/2;
    }
    return s;
}

LL BMOD(string s) // returns remainder when a binary number in string s is divided by a decimal number a
{ 
    LL res=0, a=1;
    RREP(i, s.length()-1, -1, 1)
    {
        res+=a*(s[i]-'0');
        a*=2;
    }
    return res;
}

LL NOD(LL n) // returns the number of divisors of n
{ 
    LL ans=0, x=sqrt(n);
    if(x%1==0)
    {
        REP(i, 1, x+1, 1)
        {
            if(n%i==0) ans+=2;
            if(n==i*i) ans--;
        }
    }
    else
    {
        REP(i, 0, x, 1) if(n%i==0) ans+=2;
    }
    return ans;
}

LL PF(LL n) // returns all the prime factors of a number n in a vector
{   
    VL v;
    while(n%2==0)  
    {  
        v.PB(2); 
        n = n/2;  
    }  
    REP(i, 3, sqrt(n)+1, 2)
    {  
        LL x=1;
        while(n%i==0)  
        {  
            if(x==1) v.PB(i);
            x++;
            n = n/i;  
        }  
    }
    if (n>2) v.PB(n);  
    return v[0];
}  

LL FACT(LL n) // returns factorial of a number n
{ 
    if (n==0) 
    return 1; 
    return n*FACT(n-1); 
}

DB DIST(LL x1, LL y1, LL x2, LL y2) // returns the euler distance between two points in a 2D plane
{ 
    LL dx=x1-x2, dy=y1-y2;
    return(pow(dx*dx+dy*dy, 0.5));
}

LL MODEXP(LL x, LL n, LL m) // return modular exponential of x with power n wrt m
{ 
    if (n == 0) return 1;
    else if (n % 2 == 0) return MODEXP(((x%m) * (x%m)) % m, n / 2, m)%m; 
    else return (x * MODEXP(((x%m) * (x%m)) % m, (n - 1) / 2, m) % m)%m; 
} 
  
VL SOE(LL n) // returns a vector containing all the primes upto the number n 
{
    VL v;
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for(LL p=2; p*p<=n; p++) 
    { 
        if(prime[p]==true) 
        { 
            for(LL i=p*p; i<=n; i += p) 
                prime[i]=false; 
        } 
    }
    for(LL p=2; p<=n; p++) 
       if(prime[p]) 
            v.PB(p);
    return v; 
}

LL GCD(LL a, LL b) // returns gcd of a and b
{ 
    if (b == 0) 
        return a; 
    return GCD(b, a % b); 
} 

LL LCM(LL arr[], LL n) // returns lcm of a and b
{
    LL ans = arr[0]; 
    for(LL i = 1; i < n; i++) 
        ans=(((arr[i] * ans))/(GCD(arr[i], ans))); 
    return ans; 
}

LL GFM(LL a, LL b, LL m) // returns mod of a fraction wrt m
{ 
    LL c = GCD(a, b); 
    a = a / c; 
    b = b / c; 
    LL d = MODEXP(b, m - 2, m); 
    LL ans = ((a % m) * (d % m)) % m; 
    return ans; 
}

LL NOSWP(LL arr[], LL n, LL k) // subarrays with product k
{ 
    LL start = 0, endval = 0, p = 1, countOnes = 0, res = 0; 
    while (endval < n)  
    { 
        p *= (arr[endval]); 
        if(p > k) 
        { 
            while(start <= endval && p > k) 
            { 
                p /= arr[start]; 
                start++; 
            } 
        } 
        if(p == k) 
        { 
            countOnes = 0; 
            while(endval + 1 < n && arr[endval + 1] == 1) 
            { 
                countOnes++; 
                endval++; 
            } 
            res += (countOnes + 1); 
            while(start <= endval && arr[start] == 1 && k!=1) 
            { 
                res += (countOnes + 1); 
                start++; 
            } 
            p /= arr[start]; 
            start++; 
        } 
        endval++; 
    } 
    return res; 
} 

void SS(LL x, LL a[], V(VL) &v, LL n, V(LL) &anc)
{
    // cout<<v[x].size()<<endl;
    if(v[x].size()==1&&x!=1)
    {
        // cout<<1<<" "<<x<<endl;
        a[x]=1;
    }
    else
    {  
        // cout<<v[x].size()<<endl;;
        REP(i, 0, v[x].size(), 1)
        {
            if(v[x][i]==anc[x]) continue;
            SS(v[x][i], a, v, n, anc);
            // cout<<a[v[x][i]]<<endl;
            a[x]+=a[v[x][i]];
        }
        a[x]+=1;
        // cout<<a[x]<<endl;
    }
}

void BFS(V(V(P(LL))) &v, LL s, LL k, LL n){
    V(LL) sk;
    bool vi[n]={false};
    queue<LL> q;
    q.push(s);
    vi[s]=true;
    LL d[n]={0};
    while(!q.empty()){
        LL s=q.front();
        q.pop();
        // cout<<s<<endl;
        REP(i, 0, v[s].size(), 1){
            if(v[s][i].F==k){ 
                // cout<<2<<" "<<v[s][i].S+d[s]<<endl;
                sk.PB(v[s][i].S+d[s]);
            }
        }
        REP(i, 0, v[s].size(), 1){
            if(!vi[v[s][i].F]){
                q.push(v[s][i].F);
                vi[v[s][i].F]=true;
                // cout<<v[s][i].F<<" "<<v[s][i].F<<endl;
                d[v[s][i].F]=d[s]+v[s][i].S;
            }
        }
        // REP(i, 0, n, 1) cout<<d[i]<<" ";
        // cout<<endl;
        // LL x;
        // cin>>x;
    }
    sort(sk.begin(), sk.end());
    LL an=0;
    // cout<<sk.size()<<endl;
    // REP(i, 0, sk.size(), 1) cout<<sk[i]<<" ";
    // cout<<endl;
    if(sk.size()==0){
        an=0;
    }
    else{
        an++;
        REP(i, 1, sk.size(), 1){
            if(sk[i]==sk[i-1]) an++;
            else break;
        }
    }
    cout<<an<<endl;
}

long long moduloMultiplication(long long a, 
                            long long b, 
                            long long mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 

LL POWER(LL n, LL m){
    LL x=1;
    REP(i, 0, m, 1){
        x*=n;
    }
    return x;
}

string DTB(int n, int x) 
{ 
    // Size of an integer is assumed to be 32 bits 
    string s;
    REP(i, 0, x, 1) s.append("0");
    for (int i = x-1; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            s[x-1-i]='1';
        else
            s[x-1-i]='0';
    } 
    return s;
} 

bool comp(const pair<LL, LL> &a,const pair<LL, LL> &b){
    if(a.F==b.F) return a.S>b.S;
    return a.F>b.F;
}

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}

LL SOLVE(LL T)
{
    LL n, k, x;
    cin>>n;
    V(LL) v[n];
    LL kk[n];
    map<LL, LL> mp;
    REP(i, 0, n, 1){
        cin>>k;
        kk[i]=k;
        REP(j, 0, k, 1){
            cin>>x;
            v[i].PB(x);
            mp[x]++;
        }
    }
    LL ans=0;
    REP(i, 0, n, 1){
        REP(j, 0, kk[i], 1){
            LL a=1, b=((n*kk[i])% 998244353), c=mp[v[i][j]], d=n;
            a=GFM(a, b, 998244353);
            c=GFM(c, d, 998244353);
            a*=c;
            ans+=(a%998244353);
            ans%=998244353;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

int main()
{
    FAST(0, 0, 0, 10) // untie cin and cout
    // RW("input.txt", "output.txt") // I/O in text file
    LL T=1;
    // cin >> T;
    REP(i, 0, T, 1) SOLVE(i+1);
    return 0;
}