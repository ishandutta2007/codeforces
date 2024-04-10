#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int n;
bool in[1000005];
int upd[1000005];
vector<int> fin;
void exit(){
    printf("-1\n");
    exit(0);
}
int main(){
    scanf("%d",&n);
    int k;
    int counter=0;
    int prev=0;
    fin.push_back(-1);
    for (int x=0;x<n;x++){
        scanf("%d",&k);
        if (k>0){
            if (in[k]) exit();
            else if (upd[k]>prev) exit();

            in[k]=true;
            counter++;
        }
        else{
            k=-k;
            if (!in[k]) exit();

            in[k]=false;
            counter--;
        }
        upd[k]=x;

        if (counter==0){
            fin.push_back(x);
            prev=x;
        }
    }
    if (counter!=0) exit();
    printf("%d\n",fin.size()-1);
    for (int x=1;x<fin.size();x++){
        printf("%d ",fin[x]-fin[x-1]);
    }
}