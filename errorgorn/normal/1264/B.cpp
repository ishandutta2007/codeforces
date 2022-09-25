#include <cstdio>
#include <deque>
#include <cstdlib>
using namespace std;
int a,b,c,d;
deque<int> dq;
void rage(){
    printf("NO\n");
    exit(0);
}
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int aa=d,bb=c,cc=b,dd=a;
    if (a){
        a--;
        dq.push_back(0);   
    }
    else if (b){
        b--;
        dq.push_back(1);
    }
    else if (c){
        c--;
        dq.push_back(2);
    }
    else{
        d--;
        dq.push_back(3);
    }
    while (a+b+c+d){
        if (dq.back()==0){
            if (b) b--, dq.push_back(1);
            else goto _try_again;
        }
        else if (dq.back()==1){
            if (a) a--,dq.push_back(0);
            else if (c) c--,dq.push_back(2);
            else if (dq.front()==0) dq.push_front(1),dq.pop_back();
            else goto _try_again;
        }
        else if (dq.back()==2){
            if (b) b--,dq.push_back(1);
            else if (d) d--,dq.push_back(3);
            else goto _try_again;
        }
        else{
            if (c) c--,dq.push_back(2);
            else goto _try_again;
        }
    }
    
    printf("YES\n");
    for (int x=0;x<dq.size();x++) printf("%d ",dq[x]);
    return 0;
    _try_again:;
    dq=deque<int>();
    a=aa,b=bb,c=cc,d=dd;
    
    if (a){
        a--;
        dq.push_back(0);   
    }
    else if (b){
        b--;
        dq.push_back(1);
    }
    else if (c){
        c--;
        dq.push_back(2);
    }
    else{
        d--;
        dq.push_back(3);
    }
    while (a+b+c+d){
        if (dq.back()==0){
            if (b) b--, dq.push_back(1);
            else rage();
        }
        else if (dq.back()==1){
            if (a) a--,dq.push_back(0);
            else if (c) c--,dq.push_back(2);
            else if (dq.front()==0) dq.push_front(1),dq.pop_back();
            else rage();
        }
        else if (dq.back()==2){
            if (b) b--,dq.push_back(1);
            else if (d) d--,dq.push_back(3);
            else rage();
        }
        else{
            if (c) c--,dq.push_back(2);
            else rage();
        }
    }
    
    printf("YES\n");
    for (int x=0;x<dq.size();x++) printf("%d ",3-dq[x]);
}