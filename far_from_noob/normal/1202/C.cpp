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
    cin>>t;
    //t=1;
    while(t--){
        string s;
        cin>>s;
        ll x=0,y=0;
        ll xmax=0,xmin=0,ymin=0,ymax=0;
        fo(i,s.size()){
            if(s[i]=='A')x--;
            if(s[i]=='W')y++;
            if(s[i]=='S')y--;
            if(s[i]=='D')x++;
            xmin=min(xmin,x);
            xmax=max(xmax,x);
            ymin=min(ymin,y);
            ymax=max(ymax,y);
            
        }
        map<ll,ll>m1;
        map<ll,ll>m2;
        ll flag1=0,flag2=0,f1=0,f2=0;
        x=0,y=0;
        fo(i,s.size()){
            //cout<< x<<" "<<y<<endl;
            if(x==xmax && f1==0){f1++; flag1++;}
            if(x==xmin && f1==0){f1++; }
            if(y==ymax && f2==0){f2++; flag2++;}
            if(y== ymin && f2==0){f2++;}
            if(x==xmin && (flag1%2==0 )){
                flag1++;
                m1[xmin]++;
                
            }
            if(x==xmax && flag1%2==1){
                flag1++;
                m1[xmax]++;
                
            }
            
            if(y==ymax && flag2%2==1){
            flag2++;
            m2[ymax]++;
            }
            if(y==ymin && flag2%2==0){
                flag2++;
                m2[ymin]++;
            }
            if(s[i]=='A')x--;
            if(s[i]=='W')y++;
            if(s[i]=='S')y--;
            if(s[i]=='D')x++;
            
            
        }
        if(x==xmin && flag1%2==0){
                flag1++;
                m1[xmin]++;
            }
        if(x==xmax && flag1%2==1){
            flag1++;
            m1[xmax]++;
        }
        if(y==ymax && flag2%2==1){
            flag2++;
            m2[ymax]++;
        }
        if(y==ymin && flag2%2==0){
            flag2++;
            m2[ymin]++;
        }
        //cout<<xmin<<" "<<xmax<<endl;
        //cout<<m1[xmin]<<" "<<m1[xmax]<<endl;
        //cout<<m2[ymin]<<" "<<m2[ymax]<<endl;
        ll xt = xmax+1-xmin;
        ll yt= ymax-ymin+1;
        ll temp1=0,temp2=0;
        if(m1[xmin]==1 && m1[xmax]==1)temp1=1;
        if(m2[ymin]==1 && m2[ymax]==1)temp2=1;
        if(xt>2 && yt>2 && temp1==1 && temp2==1)cout<<(min(yt,xt) -1) * max(yt,xt);
        else if(xt>2 && temp1==1)cout<<(xt-1)*(yt);
        else if(yt>2&& temp2==1)cout<<(yt-1)*(xt);
        else cout<<xt*yt;
        cout<<endl;
        
    }

    return 0;
}