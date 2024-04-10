#include<iostream>  
#define maxn 10000005  
using namespace std;  
  
int n,i,k,s[maxn],sum[maxn],a[maxn];  
char st[maxn];  
long long ans;  
  
int main()  
{  
    cin >> k >> st;  
    for(i=1;st[i-1]!=0;++i)  
        a[i]=st[i-1]-48,s[i]=s[i-1]+a[i];  
    n=i-1;  
    sum[0]++;  
    for(i=1;i<=n;++i)  
    {  
        if (s[i]>=k)  
            ans+=sum[s[i]-k];  
        sum[s[i]]++;  
    }  
    cout << ans << endl;  
    return 0;  
}