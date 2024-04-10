#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll a[200005][26];
ll n,k,t,m,q,x,flag=0;
string s;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
void find(string s1,ll low,ll high,ll* m1){
    ll flag=1;
    ll mid=(low+high)/2;
    //cout<<mid<<endl;
    for(int i=0;i<26;i++){
        if(a[mid][i]>=m1[i]);
        //else if(a[mid][i]>m1[i])flag=2;
        else {flag=0;break;}
    }
    //cout<<flag<<endl;
    if(flag==0){find(s1,mid+1,high,m1);return;}
    //if(flag==2)find(s1,mid+1,high,m1);
    if(flag==1 && m1[s[mid]-'a']==a[mid][s[mid]-'a'])cout<<mid+1<<endl;
    else find(s1,low,mid,m1);

    return;


}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        cin>>n;


        fo(i,n){
            fo(j,26)a[i][j]=0;
        }
        cin>>s>>q;
        a[0][s[0]-'a']++;
        for(int i=1;i<n;i++){
            fo(j,26)a[i][j]=a[i-1][j];
            a[i][s[i]-'a']++;

        }

        fo(j,q){
            ll m1[26];
            fo(i,26)m1[i]=0;
            string s1;
            cin>>s1;
            for(int i=0;i<s1.size();i++){
                m1[s1[i]-'a']++;
            }
            //if(j==1)fo(i,26)cout<<m1[i]<<" ";
            ll count=0;
            find(s1,0,n-1,m1);

        }


    return 0;
}