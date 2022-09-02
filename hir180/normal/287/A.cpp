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
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	char field[5][5];
	for(int i=0;i<4;i++){
		scanf("%s",&field[i]);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					int a=0,b=0;
					for(int f=k;f<=k+1;f++){
						for(int g=l;g<=l+1;g++){
							if(field[f][g]=='#'){
								a++;
							}else{
								b++;
							}
						}
					}
					if(a==4 || b==4){
						puts("YES");
						return 0;
					}
				}
			}
			field[i][j]=field[i][j]=='#'?'.':'#';
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					int a=0,b=0;
					for(int f=k;f<=k+1;f++){
						for(int g=l;g<=l+1;g++){
							if(field[f][g]=='#'){
								a++;
							}else{
								b++;
							}
						}
					}
					if(a==4 || b==4){
						puts("YES");
						return 0;
					}
				}
			}
			field[i][j]=field[i][j]=='#'?'.':'#';
		}
	}
	puts("NO");
}