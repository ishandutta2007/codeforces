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
string str[50]={
	"Washington","Adams","Jefferson","Madison","Monroe",
	"Adams","Jackson","Van Buren","Harrison",
	"Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan",
	"Lincoln","Johnson","Grant","Hayes","Garfield",
	"Arthur","Cleveland","Harrison","Cleveland","McKinley",
	"Roosevelt","Taft","Wilson","Harding","Coolidge",
	"Hoover","Roosevelt","Truman","Eisenhower","Kennedy",
	"Johnson","Nixon","Ford","Carter","Reagan"
};
int main(){
	int n;
	scanf("%d",&n);
	n--;
	cout << str[n] << endl;
}