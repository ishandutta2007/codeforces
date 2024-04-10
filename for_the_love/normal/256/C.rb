I =->{gets.split.map &:to_i}
RD =->{gets.to_i}

def sg(x)
    return 2 if(x>=2562991876)
    return 1 if(x>=45212176)
    return 1 if(x>=50626)
    return 3 if(x>=6724)
    return 0 if(x>=82)
    return 2 if(x>=16)
    return 1 if(x>=4)
    return 0
end
res = 0; n = RD[]; a = I[]; a.each{|ai|
    res ^= sg(ai)
}

puts res.zero? ? "Rublo" : "Furlo"