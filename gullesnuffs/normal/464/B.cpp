#include <bits/stdc++.h>

using namespace std;

int p[8][3];
long long x[8][3];
long long v[8][8];

bool rec(int pos){
	if(pos == 8){
		bool ok=1;
		for(int i=0; i < 8 && ok; ++i){
			for(int j=i; j < 8; ++j){
				long long S=0;
				for(int k=0; k < 3; ++k){
					long long d=x[i][k]-x[j][k];
					S += d*d;
				}
				v[i][j]=S;
				v[j][i]=S;
			}
			sort(v[i], v[i]+8);
			for(int j=1; j < 8; ++j){
				if(j <= 3 && v[i][j] != v[0][1])
					ok=0;
				else if(j >= 4 && j != 7 && v[i][j] != 2*v[0][1])
					ok=0;
				else if(j == 7 && v[i][j] != 3*v[0][1])
					ok=0;
			}
		}
		if(v[0][1] == 0 || !ok)
			return false;
		if(!ok)
			return false;
		for(int i=0; i < 8 && ok; ++i){
			vector<int> vec;
			for(int j=0; j < 8; ++j){
				long long S=0;
				for(int k=0; k < 3; ++k){
					long long d=x[i][k]-x[j][k];
					S += d*d;
				}
				if(S != v[0][1])
					continue;
				vec.push_back(j);
			}
			for(int j=0; j < 3; ++j)
				for(int k=j+1; k < 3; ++k){
					long long S=0;
					for(int m=0; m < 3; ++m){
						long long d1=x[vec[j]][m]-x[i][m];
						long long d2=x[vec[k]][m]-x[i][m];
						S += d1*d2;
					}
					if(S){
						ok=0;
						break;
					}
				}
		}
		if(!ok)
			return false;
		puts("YES");
		for(int i=0; i < 8; ++i){
			printf("%I64d %I64d %I64d\n", x[i][0], x[i][1], x[i][2]);
		}
		return true;
	}
	if(!pos){
		x[0][0]=p[0][0];
		x[0][1]=p[0][1];
		x[0][2]=p[0][2];
		return rec(pos+1);
	}
	int a[3]={0, 1, 2};
	do{
		for(int i=0; i < 3; ++i)
			x[pos][i]=p[pos][a[i]];
		if(rec(pos+1))return true;
	}
	while(next_permutation(a, a+3));
	return false;
}

int main(){
	for(int i=0; i < 8; ++i)
		for(int j=0; j < 3; ++j)
			scanf("%d", p[i]+j);
	if(!rec(0))
		puts("NO");
}