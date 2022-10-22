#include <stdio.h>
#define MAX 10000005

using namespace std;

int s[2][100005], parent[MAX], occur[2][MAX];

int Min(int a, int b){
	return a<b?a:b;
}

int main()
{
	int sz[2];
	scanf("%d%d", sz, sz+1);
	for(int i=0; i < 2; ++i)
		for(int j=0; j < sz[i]; ++j)
			scanf("%d", s[i]+j);
	for(int i=1; i < MAX; ++i){
		parent[i]=-1;
		occur[0][i]=0;
		occur[1][i]=0;
	}
	for(int i=2; i < 4000; ++i){
		if(parent[i] == -1){
			parent[i]=i;
			for(int j=i*i; j < MAX; j += i)
				if(parent[j] == -1)
					parent[j]=i;
		}
	}
	for(int i=2; i < MAX; ++i)
		if(parent[i] == -1)
			parent[i]=i;
	for(int i=0; i < 2; ++i)
		for(int j=0; j < sz[i]; ++j){
			int t=s[i][j];
			while(t != 1){
				++occur[i][parent[t]];
				t/=parent[t];
			}
		}
	for(int i=1; i < MAX; ++i){
		int t=Min(occur[0][i], occur[1][i]);
		occur[0][i]=t;
		occur[1][i]=t;
	}
	printf("%d %d\n", sz[0], sz[1]);
	for(int i=0; i < 2; ++i)
		for(int j=0; j < sz[i]; ++j){
			int t=s[i][j], u=s[i][j];
			while(t != 1){
				if(occur[i][parent[t]]){
					u /= parent[t];
					--occur[i][parent[t]];
				}
				t/=parent[t];
			}
			if(j == sz[i]-1)
				printf("%d\n", u);
			else
				printf("%d ", u);
		}
	return 0;
}