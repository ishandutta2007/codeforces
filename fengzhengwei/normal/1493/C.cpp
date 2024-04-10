#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
int n,m;
const int xx=1e5+5;
char s[xx];
int t[27];
int js(int x)
{
	return x%m==0?0:m-x%m;
}
int main(){
	T=read();
	while(T--)
	{
		n=read();
		m=read();
		scanf("%s",s);
		memset(t,0,sizeof(t));
		if(n%m)
		{
			puts("-1");
			continue;
		}
		for(int i=0;i<n;i++)t[s[i]-'a']++;
		int vis=1;
		int sum=0;
		for(int i=0;i<26;i++)
		{
			if(t[i]%m)vis=0;
			sum+=js(t[i]);
		}
		if(vis)
		{
			cout<<s<<"\n";
			continue;
		}
//		cout<<sum<<"ss wqeqe"<<endl;
//		cout<<js(1)<<"\n";
		for(int i=n-1;i>=0;i--)
		{
			sum-=js(t[s[i]-'a']);
			t[s[i]-'a']--;
			sum+=js(t[s[i]-'a']);
			for(int j=s[i]-'a'+1;j<26;j++)
			{
				sum-=js(t[j]);
				t[j]++;
				sum+=js(t[j]);
				if(sum<=n-1-i)
				{
					vis=1;
					for(int k=0;k<i;k++)cout<<s[k];
					cout<<char('a'+j);
					for(int k=1;k<=n-1-i-sum;k++)cout<<"a";
					for(int k=0;k<26;k++)
					{
						for(int o=1;o<=js(t[k]);o++)cout<<char(k+'a');
					}
					puts("");
				}
				if(vis)break;
				sum-=js(t[j]);
				t[j]--;
				sum+=js(t[j]);
			}
			if(vis)break;
		}
	}
	return 0;
}
/*
4 3
123123 45564 13113 55548
1 12
2 3
3 3
*/