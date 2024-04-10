__author__ = 'Fdg'

reader=lambda:map(int,raw_input().split())

n,a,b = reader()
list=sorted(reader())
print(list[b]-list[b-1])