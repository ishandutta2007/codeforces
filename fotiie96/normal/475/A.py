s=["+------------------------+","|#.#.#.#.#.#.#.#.#.#.#.|D|)","|#.#.#.#.#.#.#.#.#.#.#.|.|","|#.......................|","|#.#.#.#.#.#.#.#.#.#.#.|.|)","+------------------------+"]
k=input()
a=[]
for i in range(len(s[0])):
	for j in range(len(s)):
		if s[j][i]=='#' and k>0:
			a.append([j,i])
			k-=1
for i in range(len(s)):
	p=""
	for j in range(len(s[i])):
		if [i,j] in a: p+='O'
		else: p+=s[i][j]
	print p