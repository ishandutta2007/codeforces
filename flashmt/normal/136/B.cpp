#include <iostream>
#include <algorithm>
using namespace std;

int a[1010],A,b[1010],B;

void conv(int x,int a[],int &A)
{
	while (x) a[++A]=x%3, x/=3;
	if (!A) A++;
}

int main()
{
	int x;
	cin >> x;
	conv(x,a,A);
	cin >> x;
	conv(x,b,B);
	x=0;
	for (int i=max(A,B);i;i--) a[i]=b[i]+3-a[i], a[i]%=3, x=x*3+a[i];
	cout << x << endl;
}