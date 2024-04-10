#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> P;
typedef pair<p,p> p2;
#define p push
#define pb push_back
#define mp make_pair
char str[100005];
int main(){
	bool p=false;
	scanf("%s",&str);
	int leng=strlen(str);
	for(int i=0;i<leng;i++){
		if(!(str[i]-'0')){
			p=true;
			for(int j=0;j<i;j++){
				printf("%c",str[j]);
			}
			for(int j=i+1;j<leng;j++){
				printf("%c",str[j]);
			}
			printf("\n");
			break;
		}
	}
	if(!p){
			for(int j=1;j<leng;j++){
				printf("%c",str[j]);
			}		
			printf("\n");
	}
	return 0;
}