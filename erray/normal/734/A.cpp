#include <bits/stdc++.h>
typedef long long  ll;
typedef unsigned long long int ull;
#define st first 
#define nd second 
#define pb push_back
#define mp make_pair 
#define MAX 1000000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define IT iterator 
#define ln "\n"
#define mid (start + end)/2
#define R(ii) (ii * 2) + 1
#define L(ii) (ii * 2)
#define pp pair<ll,ll>  
#define vi vector<ll> 
#define all(vv) vv.begin(),vv.end()
#define N 1000005
using namespace std;       
ll n;
string s;
ll arr[200];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);  
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> s;
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++){
        arr[s[i]]++;
    }
    if (arr['D'] > arr['A']){
        cout << "Danik";
    }
    else if (arr['D'] == arr['A']){
        cout << "Friendship";
    }
    else {
        cout << "Anton";
    }
    
}