#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
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
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
string s3,s4;
int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    return (res > n/2)? n/2 : res; 
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>t;
    //t=1;
    while(t--){
        
        string s;
        cin>>s;
        //fo(i,s.size())printf("%c",s[i]);
        ll l=s.size();
        ll temp=0;
        for(int i=0;i<l/2;i++){
            if(s[i]==s[l-1-i])temp++;
            else break;
        }
        ll maxi=0,index1=temp-1;
        string s1,s2;
        for(int i=temp;i< l-temp; i++){
            s1.pb(s[i]);
            s2.pb(s[l-1-i]);
        }
        
        //fo(i,s1.size())cout<<s1[i];cout<<endl;
        // ll l1= longestPrefixSuffix(s1) , l2= longestPrefixSuffix(s2);
        if(s1.size()==0){
            fo(i,temp)cout<<s[i];
            for(int i=l-temp;i<l;i++)cout<<s[i];
            cout<<endl;
            continue;
        }
    string ss=s; 
    string rev="",str=s1;
    s=s1;
    //cout<<s;
    int m=s.size(),longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m; 
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    int n=s.size(),z[n+4],le=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            le=r=i;
            while(r<n && s[r-le]==s[r])
                r++;
            z[i]=r-le,r--;
        }
        else{
            int k=i-le;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                le=i;
                while(r<n && s[r-le]==s[r])
                    r++;
                z[i]=r-le,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
    ll l1=longestPalindromicPrefix;
    //cout<<l1;

    rev="";str=s2;
    s=s2;
    //cout<<s;
     m=s.size();longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m; 
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    n=s.size(),z[n+4],le=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            le=r=i;
            while(r<n && s[r-le]==s[r])
                r++;
            z[i]=r-le,r--;
        }
        else{
            int k=i-le;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                le=i;
                while(r<n && s[r-le]==s[r])
                    r++;
                z[i]=r-le,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
    ll l2=longestPalindromicPrefix;
    //cout<<l2;

        s=ss;       
        if(l1>=l2){
            fo(i,temp+l1)cout<<s[i];
            for(int i=l-temp;i<l;i++)cout<<s[i];
        }
        else{
            fo(i,temp)cout<<s[i];
            for(int i=l-temp-l2;i<l;i++)cout<<s[i];
        }
        cout<<endl;


        
        
    }

    return 0;
}