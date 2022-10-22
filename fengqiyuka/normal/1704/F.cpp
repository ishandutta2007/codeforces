#include<bits/stdc++.h>
using namespace std;

const int N=5e5+100;
char s[N];int sta[N];
int a[2100][2];bool bk[2100];

int main()
{
//	freopen("F.out","w",stdout);
	
	for(int i=1;i<=1000;i++){
		memset(bk,true,sizeof(bk));
		for(int j=0;j<=i-1;j++){
			int t=(a[j][0]^a[i-1-j][0]);
			bk[t]=false;
		}
		if(i>=2){
			for(int j=0;j<=i-2;j++){
				int t=(a[j][1]^a[i-2-j][1]);
				bk[t]=false;
			}
		}
		int id=0;
		while(!bk[id]) id++;
		a[i][0]=id;
		
		memset(bk,true,sizeof(bk));
		for(int j=0;j<=i-1;j++){
			int t=(a[j][0]^a[i-1-j][1]);
			bk[t]=false;
		}
		id=0;
		while(!bk[id]) id++;
		a[i][1]=id;
	}
	
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n;scanf("%d",&n);
		scanf("%s",s+1);
		
		int Sum1=0,Sum2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='R') Sum1++;
			if(s[i]=='B') Sum2++;
		}
		if(Sum1!=Sum2){
			if(Sum1>Sum2) printf("Alice\n");
			if(Sum1<Sum2) printf("Bob\n");
			continue;
		}
		
		int tot=0;
		for(int i=1;i<=n;i++){
			int id=i;
			while(id<n&&s[id+1]!=s[id]) id++;
			sta[++tot]=id-i+1;
			i=id;
		}
		
		int Ans=0;
		for(int i=1;i<=tot;i++){
			int t=sta[i]/2,ty=sta[i]%2;
			if(t>300){
				int tt=(t-300)/17+1;
				t=t-tt*17;
			}
			Ans^=a[t][ty];
		}
		if(!Ans) printf("Bob\n");
		else printf("Alice\n");
	}
	
	return 0;
}