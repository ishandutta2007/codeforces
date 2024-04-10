#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    set<int> s;
    for(int i =0;i<n;i++){
        char c[1005];
        scanf("%s",c);
        int sum=0;
        for(int j=0;c[j]!=0;j++){
            sum|=1<<(c[j]-'a');
        }
		//printf("%d\n",sum);
        s.insert(sum);
    }
    printf("%d\n",s.size());
}