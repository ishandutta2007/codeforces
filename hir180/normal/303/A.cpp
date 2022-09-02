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
	int n;
	cin >> n;
	if(n%2==0){
		puts("-1");
		return 0;
	}
	else
	{
		for(int j=0;j<2;j++)
		{
			for(int i=0;i<n;i++)
			{
				printf("%d%c",i,i==n-1?'\n':' ');
			}
		}
		for(int i=0;i<n;i++)
		{
			int r=i*2;
			r%=n;
			printf("%d%c",r,i==n-1?'\n':' ');
		}
	}
	cin >> n;
}