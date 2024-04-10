/*
LCJ AK IOI
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,ans;
char Map[MAXN][MAXN];
int main(){
	n=read();
	for(int i=1;i<=n;i++) 
	    for(int j=1;j<=n;j++) 
	        cin>>Map[i][j];
		    //scanf("%c",Map[i][j]);
	for(int i=2;i<n;i++) for(int j=2;j<n;j++) 
	    if(Map[i][j]=='X' && Map[i][j]==Map[i-1][j-1] && Map[i][j]==Map[i+1][j-1] && Map[i][j]==Map[i-1][j+1] && Map[i][j]==Map[i+1][j+1]) ans++;
	cout<<ans;	 
	return 0;
}