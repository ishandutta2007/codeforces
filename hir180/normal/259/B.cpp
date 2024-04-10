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
int main(){
	int num[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&num[i][j]);
		}
	}
	if(num[0][0]){
		num[1][1]=(num[0][0]+num[2][2])/2;
		num[0][2]=num[1][1]*3-num[0][0]-num[0][1];
		num[2][0]=num[1][1]*2-num[0][2];
	}else{
		num[1][1]=(num[0][2]+num[2][0])/2;
		num[0][0]=num[1][1]*3-num[0][2]-num[0][1];
		num[2][2]=num[1][1]*2-num[0][0];
	}
	for(int i=0;i<3;i++){
		printf("%d %d %d\n",num[i][0],num[i][1],num[i][2]);
	}
	return 0;
}