#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,cnt[26];
int main()
{
	cin>>T;
	while(T--)
	{
		For(i,0,25)cnt[i]=0;string s;cin>>s;int N=s.length();for(auto i:s)cnt[i-'a']++;
		bool flag=0;For(i,0,25)if(cnt[i]==N){while(N--)putchar(i+'a');putchar('\n');flag=1;break;}if(flag==1)continue;
		For(i,0,25)if(cnt[i]==1){putchar(i+'a');cnt[i]=0;For(j,0,25)while(cnt[j]--)putchar(j+'a');putchar('\n');flag=1;break;}if(flag)continue;
		int x=0;while(!cnt[x])x++;if(N+2>=cnt[x]*2){putchar(x+'a');putchar(x+'a');cnt[x]-=2;For(i,0,25)if(i!=x)while(cnt[i]--)putchar(i+'a'),cnt[x]&&cnt[x]--&&putchar(x+'a');putchar('\n');continue;}
		int y=x+1;while(!cnt[y])y++;if(cnt[x]+cnt[y]==N){putchar(x+'a');cnt[x]--;while(cnt[y]--)putchar(y+'a');while(cnt[x]--)putchar(x+'a');putchar('\n');continue;}
		putchar(x+'a');cnt[x]--;putchar(y+'a');cnt[y]--;while(cnt[x]--)putchar(x+'a');int z=y+1;while(!cnt[z])z++;putchar(z+'a');cnt[z]--;while(cnt[y]--)putchar(y+'a');For(i,0,25)For(j,1,cnt[i])putchar(i+'a');putchar('\n');
	}
	return 0;
}