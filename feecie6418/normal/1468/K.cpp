
#include<bits/stdc++.h>
using namespace std;
char str[5005];
int n;
bool Try(int x,int y){
	int cx=0,cy=0;
	for(int i=1;i<=n;i++){
		int tx=cx,ty=cy;
		if(str[i]=='L')cx--;
		if(str[i]=='R')cx++;
		if(str[i]=='D')cy--;
		if(str[i]=='U')cy++;
		if(cx==x&&cy==y)cx=tx,cy=ty;
	}
	return (cx==0&&cy==0);
}
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>str+1,n=strlen(str+1);
		int cx=0,cy=0,flag=0,ansx=0,ansy=0;
		for(int i=1;i<=n;i++){
			if(str[i]=='L')cx--;
			if(str[i]=='R')cx++;
			if(str[i]=='D')cy--;
			if(str[i]=='U')cy++;
			if((cx||cy)&&Try(cx,cy))ansx=cx,ansy=cy;
		}
		printf("%d %d\n",ansx,ansy);
	}
	return 0;
}