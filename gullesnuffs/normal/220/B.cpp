#include <stdio.h>
#include <map>
using namespace std;

int aSize, queryN, a[100005], occurN[100005], number[100005], maxInd=0, consider[1000], considerN=0, occur[500][100005];

map<int, int> ind;

int main()
{
	scanf("%d%d", &aSize, &queryN);
	for(int i=0; i < aSize; ++i){
		scanf("%d", a+i);
		int id=ind[a[i]];
		if(id)
			++occurN[id];
		else{
			++maxInd;
			ind[a[i]]=maxInd;
			occurN[maxInd]=1;
			number[maxInd]=a[i];
		}
	}
	for(int i=1; i <= maxInd; ++i){
		if(occurN[i] >= number[i]){
			consider[considerN]=i;
			occur[considerN][0]=0;
			for(int j=0; j < aSize; ++j)
				occur[considerN][j+1]=occur[considerN][j]+((a[j] == number[i])?1:0);
			++considerN;
		}
	}
	for(int i=0; i < queryN; ++i){
		int l, r, ans=0;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		for(int j=0; j < considerN; ++j){
			if(occur[j][r+1]-occur[j][l] == number[consider[j]])
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}