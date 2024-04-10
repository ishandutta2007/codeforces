#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char str[15],tmp[19];
int cnt;
char ans[500006][17];
bool can[11]={0};

void split(int len,int pos,int left) {
    if (left==0&&pos==len) {
        tmp[len+3]='\0';
        memcpy(ans[cnt],tmp,sizeof(ans[cnt]));
        ++cnt;
        return;
    }
    if (left==0||pos==len) return;
    int val=0;
    for(int i=pos;i<len;++i) {
        if (i!=pos&&val==0) return;
        val=val*10+(str[i]-'0');
        if (val>255) return;
        tmp[i+(4-left)]=str[i];
        if (left>1) tmp[i+(4-left)+1]='.';
        split(len,i+1,left-1);
    }
}

int nmask=0;

void gen(int len,int pos,int mask = 0) {
    if (pos==(len+1)/2) {
        if (mask==nmask) split(len,0,4);
        return;
    }
    for(char c='0';c<='9';++c) {
        if (!can[c-'0']) continue;
        str[pos]=str[len-1-pos]=c;
        gen(len,pos+1,mask|(1<<(c-'0')));
    }
}


void solve(int len) {
    gen(len,0);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int k,a;
    scanf("%d",&k);
    for(int i=0;i<k;++i) {
        scanf("%d",&a);
        can[a]=true;
        nmask|=(1<<a);
    }
    for(int len=4;len<=12;++len) {
        solve(len);
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i)
        puts(ans[i]);
    return 0;
}