#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct bitset{
    unsigned long long arr[3130]={};
    unsigned long long AF=-1ull;
    
    void flip(int l,int r){
        arr[l/64]^=(1ull<<(l%64))-1;
        if (r%64==63) arr[r/64]^=AF;
        else arr[r/64]^=(1ull<<(r%64+1))-1;
        l/=64,r/=64;
        if (l==r) return;
        arr[l]^=AF;
        
        for (int x=l+1;x<r;x++) arr[x]^=AF;
    }
    
    int get(int i){
        if (arr[i/64]&(1ull<<(i%64))) return 1;
        else return 0;
    }
    
    int get1(int i){
        //search [i%64,64) on i/64 first
        unsigned long long mask=AF^((1ull<<(i%64))-1);
        
        i=i/64;
        unsigned long long temp=arr[i]&mask;
        if (temp) return i*64+__builtin_ctzll(temp);
        i++;
        while (true){
            if (arr[i]==0) i++;
            else return i*64+__builtin_ctzll(arr[i]);
        }
    }
    
    int get0(int i){
        //search [i%64,64) on i/64 first
        unsigned long long mask=AF^((1ull<<(i%64))-1);
        
        i=i/64;
        unsigned long long temp=(arr[i]^AF)&mask;
        if (temp) return i*64+__builtin_ctzll(temp);
        i++;
        while (true){
            if (arr[i]==AF) i++;
            else return i*64+__builtin_ctzll(arr[i]^AF);
        }
    }
    
    int gethigh(){
        int i=3129;
        while (true){
            if (arr[i]==0) i--;
            else return i*64+63-__builtin_clzll(arr[i]);
        }
    }
} BS;

int n,q;
int arr[200005];

void add(int i){
    BS.flip(i,BS.get0(i));
}

void del(int i){
    BS.flip(i,BS.get1(i));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
    
    cin>>n>>q;
    rep(x,1,n+1) cin>>arr[x];
    rep(x,1,n+1) add(arr[x]);
    
    int a,b;
    while (q--){
        cin>>a>>b;
        del(arr[a]);
        arr[a]=b;
        add(arr[a]);
        
        cout<<BS.gethigh()<<endl;
    }
}