#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[105];
int main(){
	int Q;
	scanf("%d",&Q);
	while(Q-->0)
	{
		scanf("%d %d",&n,&m);
		scanf("%s",s+1);
		while(m-->0)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			bool flag=false;
			for(int i=2;i<=n-1;++i)
			{
				for(int j=l;j<=r-1;++j)
				{
					int pos=l;
					for(int k=1;k<i;++k)	if(pos<=j && s[pos]==s[k])	++pos;
					if(pos<=j)	continue;
					pos=j+1;
					for(int k=i+1;k<=n;++k)	if(pos<=r && s[pos]==s[k])	++pos;
					if(pos>r)
					{
						flag=true;
						break;
					}
				}
				if(flag)	break;
			}
			if(!flag)	puts("NO");
			else	puts("YES");
		}
	}
	return 0;
}