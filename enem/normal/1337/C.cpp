#include <cstdlib>
#include <iostream>
#include<bits/stdc++.h>
 
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<set>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define ll long long
#define ld long double
#define pb push_back
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define B begin()
#define E end()
#define S size()
#define m9 1000000007
using namespace std;
bool f1(pll x,pll y){return x.first<y.first;}
bool f2(pll x,pll y){return x.first>y.first;}
bool f3(ll x,ll y){
    return x>y;
    }
/*
vector<bool>visit;vector<vll>gr;
void dfs(ll x){
    if (visit[x]==true){return;}
    visit[x]=true;
    for(ll y:gr[x])
        {dfs(y);}
    }
}
*/
 
/*
string fs(string str1, string str2)
{    if (str1.length() > str2.length())
        swap(str1, str2);
      string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
      int carry = 0;
      for (int i=n1-1; i>=0; i--)
    {
 
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
      for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
      if (carry)
        str.push_back(carry+'0');
      reverse(str.begin(), str.end());
 
    return str;
}*/
 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
/*
ll gcdextended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    int gcd = gcdextended(b%a, a, &x1, &y1); 
   
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
 
 
///RELATIVE COPRIME
ll modinverse(ll a, ll m) 
{ 
    ll x, y; 
   ll g = gcdextended(a, m, &x, &y); 
    if (g != 1) 
return -1;
    else
    { 
        ll res = (x%m + m) % m; 
        return res;  
    } 
} 
  */
ll powmod(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = powmod(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 
///M IS PRIME
ll modif(ll x,ll m){
return(powmod(x,m-2,m));
 
}
 
bool fa(vll x,vll y){return x[1]>y[1];}
bool fao(vll x,vll y){return x[2]<y[2];}
bool fs(vll x,vll y){return x.S>y.S;}
 
 
 
 
 
 
 
int main()
{ fastio;
///freopen("input.txt", "r", stdin); 
///freopen("output.txt", "w", stdout); 
 
 
ll n;cin>>n;ll k;cin>>k;
map<ll,vll>gr;
forl(i,0,n-1){
    ll x,y;cin>>x>>y;
    x--;y--;
    gr[x].pb(y);
    gr[y].pb(x);
}
vll cost(n,0);
vll child(n,0);
vll par(n,0);
vll vis(n,0);
vll l;
l.pb(0);vis[0]=1;ll it=0;
 
while(it!=l.S){
ll x=l[it];
for(auto y:gr[x]){
    if(!vis[y]){
        vis[y]++;
        l.pb(y);
        par[y]=x;
        child[x]++;
        cost[y]=cost[x]+1;
    }
 
}
 
 
it++;
}
 
for(ll i=n-1;i>=0;i--){
    ll x=l[i];
    ll y=par[x];
    child[y]+=child[x];
     //   cout<<x<<" "<<y<<endl;
      // cout<<child[x]<<" "<<child[y]<<endl;
}
 
 
//for(auto x:cost){cout<<x<<" ";}cout<<endl;
//for(auto x:child){cout<<x<<" ";}cout<<endl;
vector<vll>fin;
 forl(i,0,n){vll temp;
     cost[i]-=child[i];
     temp.pb(i);temp.pb(cost[i]);
     fin.pb(temp);
     }
sort(fin.B,fin.E,fa);
 
ll ans=0;
forl(i,0,k){
    ans+=fin[i][1];
   // ans-=child[fin[i][0]];
}
cout<<ans;
 
 
 //testing 
 
 
return 0;
}