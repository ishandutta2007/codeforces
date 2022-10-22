
 #include <bits/stdc++.h>
#define N 5005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,a[N];
ll plist[N],pamt,t,ans[N],curr,l[N];
bool g[N][N];
vector<ll>prime[N];
ll phi[10005];
void get_pdiv(ll num,int arr)
{
    if(!num)
        return;
    for(int i=0;i<pamt;i++){
        if(num%plist[i]==0){
            int ct=0;
            while(num%plist[i]==0){
                num/=plist[i];
                ct++;
            }
            if(ct%2)
                prime[arr].push_back(plist[i]);
        }
    }
    if(num!=1)
        prime[arr].push_back(num);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(ll i=2;i<=10000;i++){
        if(!phi[i]){
            plist[pamt++]=i;
            for(ll j=i*i;j<=10000;j+=i)
                phi[j]=1;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        l[i]=i;
        cin>>a[i];
        get_pdiv(a[i],i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!a[i]||!a[j])
                continue;
            if(prime[i].size()==prime[j].size()){
                bool same=true;
                for(int k=0;k<prime[i].size();k++){
                    if(prime[i][k]!=prime[j][k]){
                        same=false;
                        break;
                    }
                }
                if(same)
                    l[j]=i;
            }/*
            if(!a[i])
                l[j]=i;*/
        }
    }
    for(int i=1;i<=n;i++){
        int cans=0,zero=0;
        for(int j=i;j<=n;j++){
            if(l[j]!=j&&i<=l[j]);
            else cans++;
            if(!a[j])
                zero++;
            //cout<<cans<<" "<<zero<<" "<<i<<" "<<j<<" "<<l[j]<<endl;
            if(cans==zero)
                ans[1]++;
            else
                ans[cans-zero]++;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}