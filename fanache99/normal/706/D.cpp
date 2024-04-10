#include<cstdio>
using namespace std;
struct TrieNode{
    int howMany;
    TrieNode *son[2];
    TrieNode(){
        this->howMany=0;
        this->son[0]=this->son[1]=NULL;
    }
};
TrieNode *root;
int answer;
void TrieUpdate(TrieNode *node,int value,int bit,int add){
    node->howMany+=add;
    if(bit==-1)
        return;
    if((value&(1<<bit))){
        if(node->son[1]==NULL)
            node->son[1]=new TrieNode();
        TrieUpdate(node->son[1],value,bit-1,add);
    }
    else{
        if(node->son[0]==NULL)
            node->son[0]=new TrieNode();
        TrieUpdate(node->son[0],value,bit-1,add);
    }
}
void TrieQuery(TrieNode *node,int value,int bit){
    if(bit==-1)
        return;
    if((value&(1<<bit)))
        if(node->son[0]!=NULL&&node->son[0]->howMany!=0){
            answer+=(1<<bit);
            TrieQuery(node->son[0],value,bit-1);
        }
        else
            TrieQuery(node->son[1],value,bit-1);
    else
        if(node->son[1]!=NULL&&node->son[1]->howMany!=0){
            answer+=(1<<bit);
            TrieQuery(node->son[1],value,bit-1);
        }
        else
            TrieQuery(node->son[0],value,bit-1);
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,x,i;
    char type;
    root=new TrieNode();
    scanf("%d\n",&n);
    TrieUpdate(root,0,30,1);
    for(i=1;i<=n;i++){
        scanf("%c %d\n",&type,&x);
        if(type=='+')
            TrieUpdate(root,x,30,1);
        if(type=='-')
            TrieUpdate(root,x,30,-1);
        if(type=='?'){
            answer=0;
            TrieQuery(root,x,30);
            printf("%d\n",answer);
        }
    }
    return 0;
}