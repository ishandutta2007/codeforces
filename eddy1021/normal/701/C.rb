#!/usr/bin/ruby

require 'set'

n = gets.chomp.to_i
c = gets.chomp

h = Hash.new(0)
s = Set.new

for i in 0...n do
  s << c[i]
end
nd = s.size
iterr = 0
got = 0
ans = n
for iterl in 0...n do
  while iterr < n && got < nd do
    if h[ c[iterr] ] == 0
      got += 1
    end
    h[ c[iterr] ] += 1
    iterr += 1
  end
  if got < nd
    break
  end
  if iterr - iterl < ans
    ans = iterr - iterl
  end
  h[ c[iterl] ] -= 1
  if h[ c[iterl] ] == 0
    got -= 1
  end
end
puts ans