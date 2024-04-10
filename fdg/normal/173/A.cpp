#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,w1=0,w2=0;
    char str1[1002]={0},str2[1002]={0};
    scanf("%d\n",&n);
    gets(str1); gets(str2);
    int l1=strlen(str1),l2=strlen(str2),left=n%(l1*l2);
    for(int i=0;i<l1*l2;++i) {
        char c1=str1[i%l1],c2=str2[i%l2];
        int win=0;
        if (c1==c2) win=0;
        else if (c1=='R'&&c2=='S'||c1=='S'&&c2=='P'||c1=='P'&&c2=='R') win=1;
        else win=-1;
        int cnt=n/(l1*l2)+(i<left);
        if (win==1) w1+=cnt;
        else if (win==-1) w2+=cnt;
    }
    cout << w2 << " " << w1 << endl;
    return 0;
}