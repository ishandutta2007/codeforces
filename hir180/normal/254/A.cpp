#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> P;
int num[700005],n;
int exi[5001]={};
vector<int>vec[5001];
bool a=false;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		scanf("%d",&num[i]);
		exi[num[i]]++;
	}
	for(int i=1;i<=5000;i++){
		if(exi[i]%2==1){
			a=true;
		}
	}
	if(a){
		puts("-1");
		return 0;
	}else{
		for(int i=0;i<2*n;i++){
			vec[num[i]].push_back(i+1);
		}
		for(int i=1;i<=5000;i++){
			for(int j=0;j<vec[i].size();j+=2){
				printf("%d %d\n",vec[i][j],vec[i][j+1]);
			}
		}
		scanf("\n");
		return 0;
	}
}