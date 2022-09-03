#include <bits/stdc++.h>
#pragma optimizer(-O2)
#define ll long long
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define mt make_tuple
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    while(t--){
        char c[1005];
        scanf("%s",c);
        set<char> s;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]==c[i+1])i++;
            else s.insert(c[i]);
        }
        for(auto it:s)
        printf("%c",it);
        printf("\n");
    }
	return 0;
}