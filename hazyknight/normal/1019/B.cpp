#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <ctime>
#include <cassert>

using namespace std;

int n;
int a[200005];
int l1,r1,l2,r2;

bool mark[200005];

int ask(int pos)
{
	if (mark[pos])
		return a[pos];
	mark[pos] = true;
	cout << "? " << pos << endl;
	fflush(stdout);
	int res;
	cin >> res;
	return res;
}

void ans(int pos)
{
	cout << "! " << pos << endl;
	fflush(stdout);
	exit(0);
}

bool in(int la,int ra,int lb,int rb)
{
	if (la > ra)
		swap(la,ra);
	if (lb > rb)
		swap(lb,rb);
	if (la >= lb && ra <= rb)
		return true;
	if (lb >= la && rb <= ra)
		return true;
	return false;
}

bool cross(int la,int ra,int lb,int rb)
{
	if (la > ra)
		swap(la,ra);
	if (lb > rb)
		swap(lb,rb);
	if (la >= lb && la <= rb)
		return true;
	if (ra >= lb && ra <= rb)
		return true;
	if (lb >= la && lb <= ra)
		return true;
	if (rb >= la && rb <= ra)
		return true;
	return false;
}

int main()
{
	cin >> n;
	a[l1 = 1] = a[r2 = n + 1] = ask(1);
	a[r1 = l2 = n / 2 + 1] = ask(n / 2 + 1);
	if (abs(a[l1] % 2) != abs(a[r1] % 2))
		ans(-1);
	if (a[l1] == a[r1])
		ans(l1);
	for (int i = 1;i <= 29;i++)
	{
		int mid1 = (l1 + r1) >> 1;
		int mid2 = (l2 + r2) >> 1;
		a[mid1] = ask(mid1);
		a[mid2] = ask(mid2);
		if (abs(a[mid1] % 2) != abs(a[mid2] % 2))
			ans(-1);
		if (a[mid1] == a[mid2])
			ans(mid1);
		if (in(a[l1],a[mid1],a[l2],a[mid2]))
			r1 = mid1,r2 = mid2;
		else if (in(a[mid1],a[r1],a[mid2],a[r2]))
			l1 = mid1,l2 = mid2;
		else if (cross(a[mid1],a[r1],a[mid2],a[r2]))
			l1 = mid1,l2 = mid2;
		else 
			r1 = mid1,r2 = mid2;
	}
	return 0;
}