#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define MAXN 1050000

using namespace std;

int len, n, h;
int b[MAXN], a[MAXN];

struct Tree{
    int worst[MAXN], change[MAXN];
    int offset;
    Tree(){
        offset=1<<18;
        for(int i=0; i < MAXN; ++i){
            worst[i]=0;
            change[i]=0;
        }
    }
    void updateChange(int dv, int pos){
        change[pos] += dv;
        if(pos == 1)
            return;
        updateChange(dv, pos/2);
    }

    void updateWorst(int pos){
        if(pos == 1)
            return;
        int l=(pos/2)*2;
        int r=l+1;
        int w1=worst[l], w2=change[l]+worst[r];
        worst[pos/2]=min(w1, w2);
        updateWorst(pos/2);
    }
    void update(int dv, int pos){
        updateChange(dv, offset+pos);
        //worst[offset+pos] += dv;
        updateWorst(offset+pos);
    }
    bool ok(){
        if(worst[1] >= 0)
            return true;
        return false;
    }
}tree;

int main()
{
    scanf("%d%d%d", &n, &len, &h);
    for(int i=0; i < len; ++i)
        scanf("%d", b+i);
    for(int i=0; i < n; ++i)
        scanf("%d", a+i);
    sort(b, b+len);
    for(int i=0; i < len; ++i)
        tree.update(-1, i);
    int ans=0, lastGood=-2*len;
    for(int i=0; i < n; ++i){
        if(a[i] >= h)
            lastGood=i;
        int p=lower_bound(b, b+len, h-a[i])-b;
        tree.update(1, p);
        if(i >= len){
            p=lower_bound(b, b+len, h-a[i-len])-b;
            tree.update(-1, p);
        }
        if(tree.ok() || (i-lastGood < len && i >= len-1))
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}