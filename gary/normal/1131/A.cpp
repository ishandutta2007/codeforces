#include<bits/stdc++.h>
using namespace std;
int w1,h1,w2,h2,maxh,maxw;
int main(){
	scanf("%d %d %d %d",&w1,&h1,&w2,&h2);
	maxh=h1+h2;
	maxw=max(w1,w2);
	printf("%d\n",(maxh+maxw)*2+4);
	return 0;
}