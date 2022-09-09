#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	bitset<26> t;
	for(char c = getchar(); c != '}'; c = getchar())
		if(c >= 'a' && c <= 'z') t[c - 'a'] = 1;
	printf("%d",(int)t.count());
	return 0;
}