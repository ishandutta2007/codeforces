#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
const char vowels[]={'a','e','i','o','u'};
vector<string> perfect; ///second words
vector<string> good; ///first words
struct word{
    string i;
    int num_vowel;
    char last_vowel;
    bool taken;
    word(string _i){
        taken=false;
        i=_i;
        num_vowel=0;
        for (int x=0;x<i.size();x++){
            for (int y=0;y<5;y++){
                if (i[x]==vowels[y]){
                    num_vowel++;
                    last_vowel=vowels[y];
                    break;
                }
            }
        }
    }
};
vector<word*> v;
bool cmp(word* i, word* j){
    if (i->num_vowel!=j->num_vowel) return i->num_vowel<j->num_vowel;
    return i->last_vowel<j->last_vowel;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    getchar();
    string s;
    char c;
    for (int x=0;x<n;x++){
        s="";
        c=getchar();
        while (c!='\n'){
            s+=c;
            c=getchar();
        }
        v.push_back(new word(s));
    }
    sort(v.begin(),v.end(),cmp);
    //for (int x=0;x<n;x++) cout<<v[x]->i<<" "<<v[x]->num_vowel<<endl;
    for (int x=1;x<n;x++){
        if (v[x]->last_vowel==v[x-1]->last_vowel && v[x]->num_vowel==v[x-1]->num_vowel){
            perfect.push_back(v[x]->i);
            perfect.push_back(v[x-1]->i);
            v[x]->taken=true;
            v[x-1]->taken=true;
            x++;
        }
    }
    //for (int x=0;x<n;x++) cout<<v[x]->i<<" "<<v[x]->taken<<endl;
    word* temp=NULL;
    for (int x=0;x<n;x++){
        if (!v[x]->taken){
            if (temp==NULL) temp=v[x];
            else if (temp->num_vowel==v[x]->num_vowel){
                good.push_back(temp->i);
                good.push_back(v[x]->i);
                temp=NULL;
            }
            else{
                temp=v[x];
            }
        }
    }
    int pairs=min( (good.size()+perfect.size())>>2, perfect.size()>>1 );
    printf("%d\n",pairs);
    for (int x=0;x<pairs;x++){
        if (good.size()>=2){
            cout<<good[good.size()-1]<<' '<<perfect[perfect.size()-1]<<'\n';
            cout<<good[good.size()-2]<<' '<<perfect[perfect.size()-2]<<'\n';
            good.pop_back();
            good.pop_back();
            perfect.pop_back();
            perfect.pop_back();
        }
        else{
            cout<<perfect[perfect.size()-1]<<' '<<perfect[perfect.size()-3]<<'\n';
            cout<<perfect[perfect.size()-2]<<' '<<perfect[perfect.size()-4]<<'\n';
            perfect.pop_back();
            perfect.pop_back();
            perfect.pop_back();
            perfect.pop_back();
        }
    }
}