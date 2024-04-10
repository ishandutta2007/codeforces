#include <stdio.h>
#define MOD 1000000007LL

using namespace std;

struct Matrix{
	long long v[55][55];
}M[1000];

int main()
{
	int nucleoN, forbN;
	long long n;
	scanf("%I64d%d%d", &n, &nucleoN, &forbN);
	--n;
	for(int i=0; i < nucleoN; ++i)
		for(int j=0; j < nucleoN; ++j)
			M[0].v[i][j]=1;
	for(int i=0; i < forbN; ++i){
		char in[3];
		int a[2];
		scanf("%s", in);
		for(int j=0; j < 2; ++j){
			if(in[j] >= 'a' && in[j] <= 'z')
				a[j]=in[j]-'a';
			else
				a[j]=in[j]-'A'+26;
		}
		M[0].v[a[0]][a[1]]=0;
	}
	for(int i=0; i < 62; ++i){
		for(int j=0; j < nucleoN; ++j)
			for(int k=0; k < nucleoN; ++k){
				M[i+1].v[j][k]=0;
				for(int m=0; m < nucleoN; ++m)
					M[i+1].v[j][k]=(M[i+1].v[j][k]+M[i].v[j][m]*M[i].v[m][k])%MOD;
			}
	}
	for(int j=0; j < nucleoN; ++j)
		for(int k=0; k < nucleoN; ++k){
			M[62].v[j][k]=0;
			M[62].v[j][j]=1;
		}
	int ans=62;
	for(int i=0; i < 62; ++i){
		if(n&(1LL<<i)){
			for(int j=0; j < nucleoN; ++j)
				for(int k=0; k < nucleoN; ++k){
					M[ans+1].v[j][k]=0;
					for(int m=0; m < nucleoN; ++m)
						M[ans+1].v[j][k]=(M[ans+1].v[j][k]+M[ans].v[j][m]*M[i].v[m][k])%MOD;
				}
			++ans;
		}
	}
	long long total=0;
	for(int j=0; j < nucleoN; ++j)
		for(int k=0; k < nucleoN; ++k)
			total=(total+M[ans].v[j][k])%MOD;
	int Ans=total;
	printf("%I64d", total);
	return 0;
}