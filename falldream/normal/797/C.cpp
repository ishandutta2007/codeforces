#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define INF 2000000000
#define MN 100000
#define ll long long
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

char st[MN+5];
struct node
{
    int x,pos;
    bool operator<(const node&b)const{return x==b.x?pos>b.pos:x>b.x;}
};
priority_queue<node> q;
int pos,ne[MN+5],la[MN+5],now;
bool mark[MN+5];

void del(int x)
{
    mark[x]=1;
    la[ne[x]]=la[x];
    ne[la[x]]=ne[x];
}

int main()
{
    scanf("%s",st+1);
    for(int i=1;st[i];++i) q.push((node){st[i]-'a',i});
    for(int i=1;st[i];i++) ne[i]=i+1,la[i]=i-1;
    while(!q.empty())
    {
        while(!q.empty()&&q.top().pos<pos) q.pop();
        if(q.empty()) break;
        int x=q.top().x;
        if(now&&x>=st[now]-'a') printf("%c",st[now]),del(now),now=la[now];
        else
        {
            pos=q.top().pos;printf("%c",q.top().x+'a');
            del(pos);now=la[pos];q.pop();
        }
    }
    for(;pos;pos--) if(!mark[pos])printf("%c",st[pos]);
    return 0;
}