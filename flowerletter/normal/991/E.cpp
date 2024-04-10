#include <iostream>
#define int long long
using namespace std;
int cnt[100],C[50][50];
signed main(int argc, char** argv) {
	string s;
	cin >>s ;
	int ans=0;
	C[0][0]=1;
	for(int i=1;i<=49;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(auto x:s) ++cnt[x-'0'];
	for(int i0=!!cnt[0];i0<=cnt[0];i0++)
	for(int i1=!!cnt[1];i1<=cnt[1];i1++)
	for(int i2=!!cnt[2];i2<=cnt[2];i2++)
	for(int i3=!!cnt[3];i3<=cnt[3];i3++)
	for(int i4=!!cnt[4];i4<=cnt[4];i4++)
	for(int i5=!!cnt[5];i5<=cnt[5];i5++)
	for(int i6=!!cnt[6];i6<=cnt[6];i6++)
	for(int i7=!!cnt[7];i7<=cnt[7];i7++)
	for(int i8=!!cnt[8];i8<=cnt[8];i8++)
	for(int i9=!!cnt[9];i9<=cnt[9];i9++)
	{
		int x=i0+i1+i2+i3+i4+i5+i6+i7+i8+i9;
		ans+=C[x-1][i0]*
		C[x-i0][i1]*
		C[x-i1-i0][i2]*
		C[x-i2-i0-i1][i3]*
		C[x-i1-i0-i2-i3][i4]*
		C[x-i0-i1-i2-i3-i4][i5]*
		C[x-i0-i1-i2-i3-i4-i5][i6]*
		C[x-i0-i1-i2-i3-i4-i5-i6][i7]*
		C[x-i0-i1-i2-i3-i4-i5-i6-i7][i8]*
		C[x-i0-i1-i2-i3-i4-i5-i6-i7-i8][i9];
	}
	cout << ans;
	return 0;
}