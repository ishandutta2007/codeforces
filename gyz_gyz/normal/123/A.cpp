#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 2000
using namespace std;
char s[N];int c[N],p[N],r[N],n,nw,tot,ma,al,u;
int main(){
	scanf("%s",s);n=strlen(s);
	rep(i,0,n-1)c[s[i]-'a']++;
	rep(i,2,n){u=0;
		rep(j,1,tot)if(i%p[j]==0){u=1;if(r[p[j]])r[i]=1,al++;break;}
		if(!u){
			p[++tot]=i;
			if(2*i<=n||i==2)r[i]=1,al++;
		}
	}ma=0;
	rep(i,1,25)if(c[i]>c[ma])ma=i;
	if(c[ma]<al){printf("NO\n");return 0;}
	printf("YES\n");
	rep(i,1,n)if(r[i])printf("%c",ma+'a');
	else{
		while(nw<=25&&(!c[nw]||nw==ma))nw++;
		if(nw<=25)printf("%c",nw+'a');else printf("%c",ma+'a');c[nw]--;
	}printf("\n");
}