#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char k[105];
vector<int> s;
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		scanf("%s",k+1);
		int n=strlen(k+1);
		for(int i=1,r;i<=n;i=r+1)
		{
			r=i;
			int cnt=0;
			while(k[r]=='1')	++cnt,++r;
			if(cnt==0)	continue;
			s.push_back(cnt);
		}
		sort(s.begin(),s.end());
		int ans=0;
		while(!s.empty())
		{
			ans+=s[s.size()-1];
			s.pop_back();
			if(!s.empty())	s.pop_back();
		}
		printf("%d\n",ans);
	}
	return 0;
}