#include<cstdio>
#include<algorithm>
using namespace std;

inline void chk_max(int &a,int b){ if(a<b) a=b;}
inline void swap(int &a,int &b){ int t=a; a=b; b=t;}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	
	int mxx=0,mxy=0;
	while(Q--)
	{
		char c=getchar();
		while(c!='+' && c!='?') c=getchar();
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		
		if(c=='+')
			chk_max(mxx,x),
			chk_max(mxy,y);
		else
		{
			if(mxx<=x && mxy<=y) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}