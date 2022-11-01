#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){
    if(a>b)return b;
    else return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        string s;
        
        cin>>  s;
         ll a[10][10][10];
         fo(i,10)fo(j,10)fo(l,10)a[i][j][l]=11;
         //cout<<a[7][9][3]<<endl;
        fo(i,10)fo(j,10){
            fo(x,11)fo(y,11){
                if(x==0 && y==0)continue;
                a[i][j][(i*x + y*j)%10]=min(a[i][j][(i*x + y*j)%10] ,  x+y);
            }
            
            
        }
        //cout<< a[7][9][0]<<endl;
        ll ans[10][10];
        fo(i,10)fo(j,10)ans[i][j]=0;
        ll temp=0;
        fo(l,s.size()){
            fo(i,10)fo(j,10){
                if(ans[i][j]>=0){
                    if(l==0){
                        if(s[l]-'0'==0);
                        else{
                    if(a[i][j][(s[l]-'0'-temp+10)%10] <=10)ans[i][j]+=a[i][j][(s[l]-'0'-temp+10)%10] ;
                    else ans[i][j]=-1;
                        }
                    }
                    else{
                    if(a[i][j][(s[l]-'0'-temp+10)%10] <=10)ans[i][j]+=a[i][j][(s[l]-'0'-temp+10)%10] -1;
                    else ans[i][j]=-1;
                    }
                    //if(i==0 && j==1)cout<<ans[i][j]<<" ";
                }
            }
            temp=s[l]-'0';
            
        }
        fo(i,10){
            fo(j,10)cout<<ans[i][j]<< " ";
            cout<<endl;
        }
        
        
    }

    return 0;
}