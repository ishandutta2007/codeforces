#include <bits/stdc++.h>
using namespace std;
/*{{ x | (1 << k) sets the kth bit of x to one
x & ~(1 << k) sets the kth bit of x to zero
x ^ (1 << k) inverts the kth bit of x.
x & (x1) sets the last one bit of x to zero
x & x sets all the one bits to zero, except for the last one bit. 
x | (x1) inverts all the bits after the last one bit.}} SOME BIT MANIPULATION*/
//__builtin_clz(x): the number of zeros at the beginning of the number
//__builtin_ctz(x): the number of zeros at the end of the number
//__builtin_popcount(x): the number of ones in the number
//__builtin_parity(x): the parity (even or odd) of the number of ones
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define REP(i,a,b) for(ll i = a; i<=b; i++)
#define REPI(i, a, n)  for(int i = a; i >= (n); --i)
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())
#define endl "\n"
//LAZY SEGMENT TREE START
void build(ll v,ll tl,ll tr,ll st[],ll lz[],bool f[],ll a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
        lz[v]=0LL;
        f[v]=false;
        return;
    }
    build((v<<1),tl,((tl+tr)>>1),st,lz,f,a);
    build((v<<1)|1,((tl+tr)>>1)+1,tr,st,lz,f,a);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    lz[v]=0LL;
    f[v]=false;
    return;
}
 
void push(ll v,ll tl,ll tr,ll st[],ll lz[],bool f[])
{
    if(f[v])
    {
        //operation
        st[(v<<1)]=lz[(v<<1)]=st[(v<<1)|1]=lz[(v<<1)|1]=0LL;
        f[(v<<1)]=f[(v<<1)|1]=true;
        f[v]=false;
    }
    //operation
    st[(v<<1)]+=lz[v]*(((tl+tr)>>1)-tl+1);
    //operation
    lz[(v<<1)]+=lz[v];
    //operation
    st[(v<<1)|1]+=lz[v]*(tr-((tl+tr)>>1));
    //operation
    lz[(v<<1)|1]+=lz[v];
    lz[v]=0LL;
    return;
}
 
void update(ll v,ll tl,ll tr,ll l,ll r,ll val,bool set,ll st[],ll lz[],bool f[])
{
    if(l>r)
    {
        return;
    }
    if(l==tl&&tr==r)
    {
        if(set)
        {
            //operation
            st[v]=lz[v]=0LL;
            f[v]=true;
        }
        //operation
        st[v]+=val*(tr-tl+1);
        //operation
        lz[v]+=val;
        return;
    }
    push(v,tl,tr,st,lz,f);
    update((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),val,set,st,lz,f);
    update((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,val,set,st,lz,f);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    return;
}
 
ll query(ll v,ll tl,ll tr,ll l,ll r,ll st[],ll lz[],bool f[])
{
    if(l>r)
    {
        return 0LL;
    }
    if(l==tl&&tr==r)
    {
        return st[v];
    }
    push(v,tl,tr,st,lz,f);
    //operation
    return query((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),st,lz,f)+query((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,st,lz,f);
}
//LAZY SEGMENT TREE END
 
// SEGMENT TREE START
 void build(int v,int tl,int tr,int a[],long long st[]) // building the segment tree
{
    if(tl==tr) // when reaching the leaf node giving segment tree value the given array value
    {
        st[v]=a[tl];
        return;
    }
    int tm=((tl+tr)/2); // distributing the value of present node in two successor nodes
    build(2*v,tl,tm,a,st); // left end to middle
    build(2*v+1,tm+1,tr,a,st); // middle to right end
    st[v]=st[v*2]+st[v*2+1]; // giving value to the parent of the two succesor nodes
    return;
}
 
void update(int v,int tl,int tr,int pos,int val,long long st[])
{
    if(tl==tr&&tl==pos) // updating the value if the reached leaf node is equal to pos
    {
        st[v]=val;
        return;
    }
    if(tl>pos||tr<pos)
    {
        return; // avoiding segmentation fault
    }
    int tm=((tl+tr)/2);// distributing the value of present node in two successor nodes
    update(2*v,tl,tm,pos,val,st);// left end to middle
    update(2*v+1,tm+1,tr,pos,val,st);// middle to right end
    st[v]=st[v*2]+st[v*2+1]; // giving value to the parent of the two succesor nodes
    return;
}
 
long long query(int v,int tl,int tr,int l,int r,long long st[])
{
    if(tl==l&&tr==r) // returning the value of the corresponding node if given range equals the range of node
    {
        return st[v];
    }
    if(l>r) // avoiding excess traversal which is not required
    {
        return 0LL;
    }
    int tm=((tl+tr)/2);
    return query(v*2,tl,tm,l,std::min(tm,r),st)+query(v*2+1,tm+1,tr,std::max(tm+1,l),r,st); // (max):- cuz cant be less than left extremity, (min):- cuz cant be greater than righ extremity
}
 
//SEGMENT TREE END
 
// DISJOINT SET UNION START
ll fn(ll x,ll rn[]) // finding the component
{
    if(x==rn[x]) // Top of its component
        return x;
    else //making parent node of each node of the component the highest node
        return rn[x]=fn(rn[x],rn);
}
 
bool un(ll x,ll y,ll rn[],ll sz[])// union of components
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y)// if connected already
        return false;
    if(sz[x]<sz[y])// otherwise connectiing light to heavy by swapping
        swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;// making parent node;
    return true;
}
 
//DISJOINT SET UNION END
ll power(ll k)
{
    ll temp=1;
    REP(i,0,k-1)
    {
        temp=temp*2;
    }
    return temp;
}
bool compare(const pair<ll,ll>&a, const pair<ll,ll>&b)
{
    return a.S<b.S;
}
pair<int,int> mostFrequent(ll arr[], ll n) 
{ 
    unordered_map<ll, ll> hash; 
    for (ll i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    ll max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    }
    pair<ll,ll> temp;
    temp.F=res;
    temp.S=max_count;
    return temp; 
}
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
ll div(ll n) 
{ 
    if (n % 2 == 0) 
        return 2; 
    for (ll i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    } 
    return n; 
}
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
bool sec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.F > b.F); 
}
bool sec1(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second > b.second); 
}
ll msum(ll a[], ll size) 
{ 
   ll max_so_far = a[0]; 
   ll curr_max = a[0]; 
  
   for (ll i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
}
vector<ll> v[200010];
vector<bool> vis(200010,0);
map<ll,ll> st;
ll um[200010];
void dfs(ll t)
{
    vis[t]=1;
    st[um[t]]++;
    for(auto u:v[t])
    {
        if(vis[u]==0)
        {
            dfs(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
    ll n,m,k;
    cin>>n>>m>>k;
    REP(i,1,n)
    {
        ll c;
        cin>>c;
        um[i]=c;
    }
    REP(i,0,m-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].PB(y);
        v[y].PB(x);
    }
    ll ans=0;
    REP(i,1,n)
    {
        if(vis[i]==0)
        {
            st.clear();
            dfs(i);
            ll mx=0;
            for(auto it:st)
                mx=max(mx,it.S);
            ll sm=0;
            for(auto it:st)
                sm+=it.S;
            ans+=(sm-mx);
        }
    }
    cout<<ans;
    return 0;
}