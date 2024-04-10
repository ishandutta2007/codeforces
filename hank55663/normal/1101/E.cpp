#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int Maxx=0,Maxy=0;
	for(int i=0;i<n;i++){
		char c;
		int x,y;
		scanf(" %c %d %d",&c,&x,&y);
		if(x<y)swap(x,y);
		if(c=='+'){
			Maxx=max(Maxx,x);
			Maxy=max(Maxy,y);
		}
		else{	
			if(x>=Maxx&&y>=Maxy)printf("YES\n");
			else printf("NO\n");
		}
	}
}