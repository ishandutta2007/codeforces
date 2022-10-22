#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],cnt[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'a'+1;}
		For(i,1,26)cnt[i]=0;For(i,1,N)cnt[a[i]]++;bool flag=0;For(i,1,26)if(!cnt[i]){cout<<char(i+'a'-1)<<endl;flag=1;break;}if(flag)continue;
		For(i,1,27*26)cnt[i]=0;For(i,2,N)cnt[a[i-1]*27+a[i]]++;For(i,1,26){For(j,1,26)if(!cnt[i*27+j]){cout<<char(i+'a'-1)<<char(j+'a'-1)<<endl;flag=1;break;}if(flag)break;}if(flag)continue;
		For(i,1,27*27*27)cnt[i]=0;For(i,3,N)cnt[a[i-2]*27*27+a[i-1]*27+a[i]]++;
		For(i,1,26){For(j,1,26){For(k,1,26)if(!cnt[i*27*27+j*27+k]){cout<<char(i+'a'-1)<<char(j+'a'-1)<<char(k+'a'-1)<<endl;flag=1;break;}if(flag)break;}if(flag)break;}
	}
	return 0;
}