#include<set>
#include<map>
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define x first
#define y second
#define N 100005
#define sqrt(x) ((x)*(x))
using namespace std;
typedef long long ll;
int main(){
	int ans=0;
	int x=0,y=0;
	int n;
	scanf("%d\n",&n);
	int u=0,r=0;
	for(int i=0;i<n;i++){
		char c;
		scanf("%c",&c);
		if(c=='U')
		{
			if(u==1||u==0){
				u=1;
			}
			else{
				u=1;
				r=0;
				ans++;
			}
			x++;
		}
		if(c=='D')
		{
			if(u==-1||u==0){
				u=-1;
			}
			else{
				u=-1;
				r=0;
				ans++;
			}
			x--;
		}
		if(c=='R')
		{
			if(r==1||r==0){
				r=1;
			}
			else{
				r=1;
				u=0;
				ans++;
			}
			x++;
		}
		if(c=='L')
		{
			if(r==-1||r==0){
				r=-1;
			}
			else{
				r=-1;
				u=0;
				ans++;
			}
			x++;
		}
	}
	ans++;
	printf("%d\n",ans);
}
/*
1 2 3 4
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44*/