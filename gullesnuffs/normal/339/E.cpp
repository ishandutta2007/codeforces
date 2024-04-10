#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define OP_OR 0
#define OP_XOR 1
#define INF 999999999
using namespace std;

int n;
int a[5][1005];
int dis[1005];
vector<int> consider;
vector<pair<int, int> > ans;
int check[1005];
int nWrong;

int getPos(int depth, int pos){
    for(int i=depth-1; i >= 0; --i){
        if(ans[i].first <= pos && ans[i].second >= pos)
            pos=ans[i].second-(pos-ans[i].first);
    }
    return a[0][pos];
}

bool rec(int depth){
    if(depth == 2 && nWrong > 2)
        return 0;
    bool ok=1;
    for(int i=0; i < n; ++i){
        int pos=check[i];
        for(int j=0; j < depth; ++j){
            if(ans[j].first <= pos && ans[j].second >= pos)
                pos=ans[j].second-(pos-ans[j].first);
        }
        if(a[0][check[i]] != pos+1){
            ok=0;
            for(int j=0; j < i; ++j){
                if(rand()%3 == 0){
                    swap(check[j], check[i]);
                    break;
                }
            }
            break;
        }
    }
    if(ok){
        return 1;
    }
    if(depth >= 3)
        return 0;
    for(int i=0; i < consider.size(); ++i)
        for(int j=i+1; j < consider.size(); ++j){
            int c1=consider[i], c2=consider[j];
            if(consider[i] > consider[j])
                swap(c1, c2);
            ++c2;
            if(c1+1 == c2)
                continue;
            ans.push_back(make_pair(c1, c2-1));
            int x=getPos(depth, c1);
            int pre=0, post=0;
            if(c1 == 0 && x > 1)
                ++pre;
            else if(c1 > 0 && abs(x-getPos(depth, c1-1)) > 1)
                ++pre;
            x=getPos(depth, c2-1);
            if(c2-1 == n-1 && x < n)
                ++pre;
            else if(c2-1 < n-1 && abs(x-getPos(depth, c2)) > 1)
                ++pre;
            x=getPos(depth+1, c1);
            if(c1 == 0 && x > 1)
                ++post;
            else if(c1 > 0 && abs(x-getPos(depth, c1-1)) > 1)
                ++post;
            x=getPos(depth+1, c2-1);
            if(c2-1 == n-1 && x < n)
                ++post;
            else if(c2-1 < n-1 && abs(x-getPos(depth, c2)) > 1)
                ++post;
            nWrong += post-pre;
            /*for(int k=0; k < c1; ++k)
                a[depth+1][k]=a[depth][k];
            for(int k=c1; k < c2; ++k){
                a[depth+1][k]=a[depth][c2-1-(k-c1)];
            }
            for(int k=c2; k < n; ++k)
                a[depth+1][k]=a[depth][k];*/
            for(int k=0; k < consider.size(); ++k)
                if(consider[k] > c1 && consider[k] < c2)
                    consider[k]=c2-(consider[k]-c1);
            bool res=rec(depth+1);
            if(res)
                return 1;
            ans.pop_back();
            for(int k=0; k < consider.size(); ++k)
                if(consider[k] > c1 && consider[k] < c2)
                    consider[k]=c2-(consider[k]-c1);
            nWrong += pre-post;
        }
        return 0;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", a[0]+i);
        dis[i]=INF;
    }
    nWrong=0;
    for(int i=0; i < n-1; ++i){
        if(abs(a[0][i]-a[0][i+1]) > 1){
            dis[i]=0;
            dis[i+1]=0;
            ++nWrong;
        }
    }
    if(a[0][0] > 1)
        dis[0]=0, ++nWrong;
    if(a[0][n-1] < n)
        dis[n-1]=0, ++nWrong;
    for(int i=0; i < n-1; ++i)
        if(dis[i+1] > dis[i]+1)
            dis[i+1]=dis[i]+1;
    for(int i=n-1; i > 0; --i)
        if(dis[i-1] > dis[i]+1)
            dis[i-1]=dis[i]+1;
    for(int i=0; i < n; ++i)
        if(dis[i] < 2)
            consider.push_back(i);
    if(dis[n-1] < 0)
        consider.push_back(n);
    for(int i=0; i < n; ++i)
        check[i]=i;
    random_shuffle(check, check+n);
    rec(0);
    printf("%d\n", ans.size());
    for(int i=ans.size()-1; i >= 0; --i){
        printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    }
    return 0;
}