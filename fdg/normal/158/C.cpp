#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

vector <string> path;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    char str[250]={0};
    for(int i=0;i<n;++i) {
        cin >> str;
        if (str[0]=='p') {
            cout << "/";
            for(int j=0;j<path.size();++j)
                cout << path[j] << "/";
            cout << endl;
        } else {
            gets(str);
            int pos=1,l=strlen(str); str[l++]='/';
            if (str[pos]=='/'&&++pos) path.clear();
            string s="";
            for(;pos<l;++pos) {
                if (str[pos]=='/') {
                    if (s[0]=='.') path.pop_back();
                    else path.push_back(s);
                    s="";
                } else s+=str[pos];
            }
        }
    }
    return 0;
}