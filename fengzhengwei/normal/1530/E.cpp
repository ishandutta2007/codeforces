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
const int xx=200005;
int t[27];
char s[xx];
signed main(){
	int T=read();
	while(T--)
	{
		scanf("%s",s);
		int n=strlen(s);
		memset(t,0,sizeof(t));
		for(int i=0;i<n;i++)t[s[i]-'a']++;
		int vs=0;
		for(int j=0;j<26;j++)
		{
			if(t[j]==1)
			{
				cout<<char('a'+j);
				t[j]--;
				for(int k=0;k<26;k++)while(t[k]--)cout<<char('a'+k);
				puts("");
				vs=1;break;
			}
			if(t[j]==n)
			{
				while(t[j]--)cout<<char('a'+j);
				puts("");
				vs=1;break;
			}
		}
		if(vs==1)continue;//1 
		int op=0;
		for(int j=0;j<26;j++)if(t[j]>=2){op=j;break;}
		if(t[op]-2<=(n-2)/2)
		{
			t[op]--;
			cout<<char('a'+op);
			int s=op+1;
			for(int j=1;j<n;j++)
			{
				if((j&1)&&t[op])
				{
					cout<<char('a'+op),t[op]--;
				}
				else 
				{
					while(!t[s])s++;
					cout<<char('a'+s);t[s]--;
				}
			}
			puts("");
			continue;
		}
		t[op]--;
		cout<<char('a'+op);
		int s=op+1;
		while(!t[s])s++;
		if(t[s]+t[op]+1==n)
		{
			while(t[s]--)cout<<char('a'+s);
			while(t[op]--)cout<<char('a'+op);
			puts("");
			continue;
		}
		cout<<char('a'+s);
		t[s]--;
//		puts("WWW");
		while(t[op]--)cout<<char('a'+op);
		int w=s+1;
		while(!t[w])w++;
		cout<<char('a'+w);
		t[w]--;
		for(int k=0;k<26;k++)
		{
			if(t[k]>0)
			{
				while(t[k]--)cout<<char('a'+k);
			}
		}
		puts("");
	}
	return 0;
}