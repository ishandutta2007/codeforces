# require 'set'

n, l, r = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)

a1 = a.take(r).drop(l - 1)
b1 = b.take(r).drop(l - 1)
a1 = a1.sort()
b1 = b1.sort()

if (a.take(l - 1) == b.take(l - 1) && a.drop(r) == b.drop(r) && a1 == b1) then
	puts "TRUTH"
else
	puts "LIE"
end