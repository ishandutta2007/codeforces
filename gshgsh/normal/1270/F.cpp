#include<algorithm>
#include<iostream>
#include<cmath>
#include<unordered_map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,M,a[MAXN],cnt[MAXN*500];ll ans;
int main()
{
	string s;cin>>s;N=s.length(),M=sqrt(N);For(i,1,N)a[i]=a[i-1]+s[i-1]-'0';
	For(i,1,M){vector<int>tmp;tmp.push_back(N);cnt[N]=1;For(j,1,N)cnt[i*a[j]-j+N]++,tmp.push_back(i*a[j]-j+N);while(!tmp.empty()){int x=tmp.back();ans+=1ll*cnt[x]*(cnt[x]-1)/2,cnt[x]=0,tmp.pop_back();}}
	For(i,1,M){int l=0,r=0;For(j,0,N-1){while(l<=N&&a[l]<a[j]+i)l++;while(r<N&&a[r+1]<=a[j]+i)r++;int tmp=max(l,j+M*i+1);if(tmp<=r)ans+=(r-j)/i-(tmp-j-1)/i;}}cout<<ans<<endl;return 0;
}