#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100100],x,n;

int main()
{
  cin >> n;
  for (int i=1;i<=n;i++) scanf("%d",&x), a[x]=i;
  for (int i=1;i<=n;i++) printf("%d ",a[i]);
}