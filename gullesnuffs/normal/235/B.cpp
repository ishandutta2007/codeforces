#include <stdio.h>

using namespace std;

double prob[100005];
double score[100005], len[100005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        scanf("%lf", prob+i);
    score[0]=0;
    len[0]=0;
    for(int i=0; i < n; ++i){
        score[i+1]=score[i]+(2*len[i]+1)*prob[i];
        len[i+1]=(len[i]+1)*prob[i];
    }
    printf("%.6lf", score[n]);
    return 0;
}