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
	char key[256];
	memset(key,0,sizeof(key));
	char c[1005],c1[1005];
	scanf("%s %s",c,c1);
	int ok=1;
	for(int i=0;c[i]!=0;i++){
        if(key[c[i]]!=0&&key[c[i]]!=c1[i])
        ok=0;
        if(key[c1[i]]!=0&&key[c1[i]]!=c[i])
        ok=0;
        key[c[i]]=c1[i];
        key[c1[i]]=c[i];
	}
	if(!ok){
	printf("-1\n");
	return 0;
	}
	int num=0;
	for(int i=0;i<256;i++)
	if(key[i]!=0&&key[i]!=i)
	num++;
	printf("%d\n",num/2);
	for(int i=0;i<256;i++)
	if(key[i]!=0&&key[i]!=i){
		printf("%c %c\n",i,key[i]);
		key[key[i]]=0;
	}
}